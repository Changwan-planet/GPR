
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import os

def overlay_cor_files_in_directory(directory_path):
    # Get all .cor files in the specified directory
    cor_files = [os.path.join(directory_path, file) for file in os.listdir(directory_path) if file.endswith('.cor')]
    
    # Overlay the cor datasets on a single plot
    plt.figure(figsize=(14, 10))
    
    for file in cor_files:
        # Read the .cor file
        data = pd.read_csv(file, sep='\t', header=None)
        data.columns = ["ID", "Date", "Time", "Latitude_Value", "Latitude_Direction", "Longitude_Value", "Longitude_Direction", "Depth", "Character", "Magnitude"]
        
        sns.scatterplot(data=data, x="Latitude_Value", y="Longitude_Value", hue="Depth", palette="viridis", marker='o', s=50, label=os.path.basename(file).replace('.cor', ''), edgecolor="none")
    
    plt.title("Overlay of .cor Data")
    plt.xlabel("Latitude")
    plt.ylabel("Longitude")
    plt.grid(True)
    plt.tight_layout()
    plt.legend(loc="upper right", title="Files")
    plt.show()

if __name__ == "__main__":
    directory_path = input("Enter the path to the directory containing .cor files: ")
    overlay_cor_files_in_directory(directory_path)
