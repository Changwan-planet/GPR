import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os

def overlay_csv_files_in_directory(directory_path):
    # Get all .csv files in the specified directory
    csv_files = [os.path.join(directory_path, file) for file in os.listdir(directory_path) if file.endswith('.csv')]
    
    # Overlay the csv datasets on a single plot
    plt.figure(figsize=(14, 10))
    
    for file in csv_files:
        data = pd.read_csv(file)
        #sns.scatterplot(data=data, x="Sampled_Latitude", y="Sampled_Longitude", hue="Sampled_Depth", palette="viridis", marker='o', s=50, label=os.path.basename(file).replace('.csv', ''), edgecolor="none")
        sns.scatterplot(data=data, x="Sampled_Latitude", y="Sampled_Longitude", hue="Sampled_Depth", palette="viridis", marker='o', s=50, edgecolor="none")
    
    plt.title("Overlay of Sampled Data")
    plt.xlabel("Latitude")
    plt.ylabel("Longitude")
    plt.grid(True)
    #plt.tight_layout()
    #plt.legend(loc="upper right", title="Files")
    plt.show()

if __name__ == "__main__":
    directory_path = input("Enter the path to the directory containing sampled .csv files: ")
    overlay_csv_files_in_directory(directory_path)