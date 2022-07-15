import os

for dir_name in os.listdir("src"):
    readme_content: str = ""
    for file_name in os.listdir(os.path.join("src", dir_name)):
        if file_name.endswith(".cpp"):
            os.remove(os.path.join("src", dir_name, file_name))
            # with open(os.path.join("src", dir_name, file_name), 'r') as f:
            #     readme_content = f.read()
            # break

    # appendage: str = "\n## My C++ Solution:\n\n```cpp\n" + readme_content + "```"
    # with open(os.path.join("src", dir_name, "README.md"), 'a') as f:
    #     f.write(appendage)
