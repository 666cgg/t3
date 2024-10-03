import subprocess
def create_file(filename):

    try:
        # 'w' 模式会创建文件（如果不存在）
        with open(filename, 'w', encoding='utf-8') as file:
            pass  # 不写入任何内容
        print("已创建配置文件")
    except IOError as e:
        print(f"Failed to create file: {e}")
filename = "Profiles.json"
create_file(filename)
exe_path = r'C:\t3_23\cmake-build-debug\t3_23.exe'
subprocess.Popen([exe_path])