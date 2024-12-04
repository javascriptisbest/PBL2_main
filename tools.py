import platform
import os

WINDOWS = 'Windows'
MACOS = 'Darwin'
LINUX = 'Linux'

# Default for Linux3
OS = LINUX
RMDIR = 'rm -rf'
MKDIR = 'mkdir -p'
CPDIR = 'cp -r'
CPFILE = 'cp'
RM = 'rm -f'
MV = 'mv'
CMAKE_RESET = 'cmake ..'
CMAKE_BUILD = 'cmake --build .'
EXEC_PATH = './build/'
EXEC_FILE = 'pbl'
CLEAR_SCREEN = 'clear'
WINDOWS_SQLITE3_DLL_FILE = ''

running = True

if platform.system() == 'Windows':
    OS = WINDOWS
    RMDIR = 'rmdir /s /q'
    MKDIR = 'mkdir'
    CPDIR = 'xcopy /s /e /i'
    CPFILE = 'copy'
    RM = 'del'
    MV = 'move'
    EXEC_PATH = '.\\build\\Debug\\'
    CLEAR_SCREEN = 'cls'
    WINDOWS_SQLITE3_DLL_FILE = 'Libraries\\sqlite3\\sqlite3.dll'
elif platform.system() == 'Darwin':
    OS = MACOS
    # Same as Linux


def reset_project():
    print('Resetting project...' )
    os.system(f'{RMDIR} build')
    os.system(f'{MKDIR} build')
    os.chdir('build')
    MSG = 'Done.'
    if os.system(f'{CMAKE_RESET}'):
        MSG = 'Failed to reset project.'
    os.chdir('..')
    print(MSG )

def build_project():
    print(  'Building project...' )
    os.chdir('build')
    MSG =  'Done.'
    if os.system(f'{CMAKE_BUILD}'):
        MSG = 'Failed to build project.'
    os.chdir('..')
    print(MSG)

def run_project():
    print( 'Running project...' )
    if (OS == WINDOWS):
        START_CMD = 'start'
    else:
        START_CMD = 'xdg-open'


    MSG = 'Done.'
    if os.system(f'{START_CMD} {EXEC_PATH}{EXEC_FILE}'):
        MSG =  'Failed to run project.'
    print(MSG)

def enter_to_continue():
    input('Press Enter to continue...')

def exit_program():
    global running
    running = False

def copy_nessesary_files():
    os.system(f'{CPDIR} res {EXEC_PATH}/res')
    if (OS == WINDOWS):
        # In Windows, we need to copy sqlite3.dll to build folder
        os.system(f'{CPFILE} {WINDOWS_SQLITE3_DLL_FILE} {EXEC_PATH}')



if __name__ == '__main__':
    while running:
        os.system(CLEAR_SCREEN)
        print('Chương trình quản lý project.')
        print('Version 1.0.0')
        print('Author: Eins\n')

        print('1. Reset project.')
        print('2. Biên dịch chương trình.')
        print('3. Chạy chương trình.')
        print('4. Thoát.')

        option = int(input('Chọn: '))

        match option:
            case 1:
                reset_project()
            case 2:
                build_project()
                if (OS == WINDOWS):
                    # In Windows, we need to do it twice
                    #   there is a bug "pwsh.exe" not found in the first time.
                    build_project()  
                copy_nessesary_files()
            case 3:
                run_project()
            case 4:
                exit_program()
            case _:
                print('Chức năng không tồn tại.')
        
        enter_to_continue()

    