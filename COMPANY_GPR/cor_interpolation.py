import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
import os

def extract_last_trace(rad_file_path):
    with open(rad_file_path, 'r') as file:
        for line in file:
            if "LAST TRACE" in line:
                return int(line.split(":")[1].strip())
    return None

def process_cor_files_in_directory(directory_path):
    # Get all .cor files in the specified directory
    cor_files = [os.path.join(directory_path, file) for file in os.listdir(directory_path) if file.endswith('.cor')]
    
    for cor_file in cor_files:
        # Determine the corresponding .rad file
        rad_file = cor_file.replace('.cor', '.rad')
        
        # Check if .rad file exists
        if not os.path.exists(rad_file):
            print(f"Warning: Corresponding .rad file for {cor_file} not found!")
            continue
        
        # Extract the "LAST TRACE" value from the .rad file
        num_points = extract_last_trace(rad_file)
        
        # Loading the .cor file into a pandas DataFrame
        df = pd.read_csv(cor_file, sep='\\t', header=None)
        df.columns = ["ID", "Date", "Time", "Latitude_Value", "Latitude_Direction", "Longitude_Value", "Longitude_Direction", "Depth", "Character", "Magnitude"]
        subset_df = df[["Latitude_Value", "Longitude_Value", "Depth"]]
        
        # Linear regression for Latitude vs. Longitude
        X = subset_df["Latitude_Value"].values.reshape(-1, 1)
        y = subset_df["Longitude_Value"].values
        model = LinearRegression()
        model.fit(X, y)
        
        # Random Forest Regression for Latitude vs. Depth
        y_depth = subset_df["Depth"].values
        forest_regressor = RandomForestRegressor(n_estimators=200)
        forest_regressor.fit(X, y_depth)
        
        # Generate sampled points based on the extracted number from the .rad file
        sampled_latitudes = np.linspace(subset_df["Latitude_Value"].min(), subset_df["Latitude_Value"].max(), num_points).reshape(-1, 1)
        sampled_longitudes = model.predict(sampled_latitudes)
        sampled_depths = forest_regressor.predict(sampled_latitudes)
        
        # Consolidate the sampled data
        sampled_data = pd.DataFrame({
            "Sampled_Latitude": sampled_latitudes.flatten(),
            "Sampled_Longitude": sampled_longitudes,
            "Sampled_Depth": sampled_depths
        })
        
        # Export to a CSV file
        csv_path = cor_file.replace('.cor', '_sampled.csv')
        sampled_data.to_csv(csv_path, index=False)
        print(f"Sampled data saved to: {csv_path}")

if __name__ == "__main__":
    directory_path = input("Enter the path to the directory containing .cor files: ")
    process_cor_files_in_directory(directory_path)


# Save the simplified script content to a .py file
#simplified_script_path = "cor_processing_script2.py"
#with open(simplified_script_path, 'w') as script_file:
#    script_file.write(simplified_script_content)

#simplified_script_path
