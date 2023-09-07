#Neelansh Khare

from genericpath import exists
from pathlib import Path
    
def recursive_dir(path):
    '''Runs when the recursive option is called -r
    Recursively outputs directory content'''
    p1 = Path(path)
    for obj in p1.iterdir():
        #Checks if object is a directory to use recursion to search further within it
        if obj.is_dir():
            print(obj)
            recursive_dir(obj)
        else:
            print(obj)


def recursive_only_files(path):
    '''Runs when the -r -f combination is called
    Recursively outputs directory content, but only the files'''
    p2 = Path(path)
    for obj in p2.iterdir():
        #Checks if object is a directory to use recursion to search further within it
        if obj.is_dir():
            recursive_dir(obj)
        #Checks if type is a file, then prints it
        elif obj.is_file():
            print(obj)


def recursive_match_name(path, name1):
    ''' Runs when the -r -s combination is called
    Recursively outputs directory content, but only the files that match the given file name '''
    p3 = Path(path)
    for obj in p3.iterdir():
        #Checks if object is a directory to use recursion to search further within it
        if obj.is_dir():
            recursive_match_name(obj, name1)
        #Checks if type is a file, then if the name matches
        elif obj.is_file():
            if obj.name == name1:
                print(obj)


def recursive_match_extension(path, suf1):
    ''' Runs when the -r -e combination is called
    Recursively outputs directory content, but only files that match the file extension '''
    p4 = Path(path)
    for obj in sorted(p4.iterdir()):
        #Checks if object is a directory to use recursion to search further within it
        if obj.is_dir():
            recursive_match_extension(obj, suf1)
        #Checks if type is a file, then if the extension matches
        elif obj.is_file():
            if obj.suffix == suf1:
                print(obj)


def run():
    ''' Main function that manages inputs and conditions based on options and commands '''
    try:
    #Try and except format used to handle errors gracefully, by printing that there is an error and then with the function is called again, requesting new input 
        input1 = input()
        command = input1[:1]
        #The command as the first character in the input


        while(command!='Q' and command!='q'):
        #While loop keeping running until the command equals q, signalling that the user wants to quit
            while(len(input1)<=1):
            #Notifies that there is an error if the input is only one character or less
                print('ERROR')
                input1 = input()
                command = input1[:1]

            while(command!='L' and command!='C' and command!='D' and command!='R'):
            #Requests new input while the command is invalid
                print('ERROR')
                input1 = input()
                command = input1[:1]
            
            if command == 'L':
            #If statement condition passes if the command L is entered, meaning the user wants to list contents of the user specified directory, regardless of with options or not
                #initializes the variable index1 for later
                index1 = -1

                if(" -r " in input1):
                    #Runs if there are two options given, with one being recursive
                    for i in reversed(range(len(input1)-3)):
                    #Iterates backwards in the input and finds index where the path stops, and options start
                        if input1[i:i+4]==' -r ':
                            index1=i
                            break
                    path1 = input1[2:index1]
                    second_option = input1[index1+4:index1+6]
                    #Second option is known to exist if there is the pattern of -r, then whitespace

                    if second_option == "-f":
                    #Passes condition when -r -f option combination is called, to recursively output only files from directory contents
                        recursive_only_files(path1)

                    elif second_option == "-s":
                    #Passes condition when -r -s option combination is called, to recursively output files that match the given file name
                        name1 = input1[index1+7:]
                        recursive_match_name(path1, name1)
            

                    elif second_option == "-e":
                    #Passes condition when -r -e option combination is called, to recursively output files that match the given file extension
                        suf1 = input1[index1+7:]
                        suf1 = '.' + suf1
                        recursive_match_extension(path1, suf1)

                    else: 
                        print('ERROR')


                elif((" -f" in input1) or (" -r" in input1) or (" -e" in input1) or (" -s" in input1)):
                #Runs when there is only one option given
                    for i in reversed(range(len(input1)-2)):
                    #Iterates backwards through input to find the index of the end of path, and start of option
                        if ((input1[i:i+3]==' -s') or (input1[i:i+3]==' -r') or (input1[i:i+3]==' -f') or (input1[i:i+3]==' -e')):
                            index1=i
                            break
                    path1 = input1[2:index1]
                    option = input1[index1+1:index1+3]
                    
                    p2 = Path(path1)

                    if(option == '-f'):
                    #Outputs only files, excluding directories when option f called
                        for obj in p2.iterdir():
                            if obj.is_file():
                                print(obj)


                    elif(option == '-s'):
                    #Outputs files that match the given file name when option s is called
                        name = input1[index1+4:]
                        for obj in sorted(p2.iterdir()):
                            if obj.name == name:
                                print(obj)
                    

                    elif(option == '-r'):
                    #Recursively outputs directory content when option r is called
                        recursive_dir(path1)


                    elif(option == '-e'):
                    #Outputs only files the match the given file extension when option e is called
                        suf = input1[index1+4:]
                        suf = '.' + suf
                        for obj in sorted(p2.iterdir()):
                            if obj.suffix == suf:
                                print(obj)
                    
                    else:
                        print("ERROR")
                                                    

                else:
                #Runs when no options are given
                    path1 = input1[2:]
                    p1 = Path(path1)
                    #First for loop prints out only files
                    for obj in sorted(p1.iterdir()):
                        if obj.is_file():
                            print(obj)
                    #Second for loop prints out the directories
                    for obj in sorted(p1.iterdir()):
                        if obj.is_dir():
                            print(obj)
                        
            
            elif command == 'C':
            #Creates a new file in the specified directory 
                index2 = -1
                for i in reversed(range(len(input1)-3)):
                    if (input1[i:i+4]==' -n '):
                        index2=i
                        break
                path1 = input1[2:index2]

                name_new_file =  input1[index2+4:]
                name_new_file = name_new_file + '.dsu'
                p = Path(".") / path1 / name_new_file
                #If the file does not exist, it gets created
                if not p.exists():
                    p.touch()
                p = Path(path1)
                #Prints out the file that is created
                for obj in p.iterdir():
                    if obj.name == name_new_file:
                        print(obj)
            

            elif command == 'D':
            #Deletes a file
                path1 = input1[2:]
                #Checks if the type is dsu, and asks for new input if not
                while(path1[-4:] != '.dsu'):
                    print("ERROR")
                    input1 = input()
                    path1 = input1[2:]
                p = Path(".") / path1 
                #If the file exists, it gets deleted 
                if p.exists():
                    p.unlink()
                    print(path1, "DELETED")
                

            elif command == 'R':
            #Reads the contents of a file
                path1 = input1[2:]
                #Checks if the type is dsu, and asks for new input if not
                while(path1[-4:] != '.dsu'):
                    print("ERROR")
                    input1 = input()
                    path1 = input1[2:]
                p = Path(".") / path1
                if p.exists():
                    f = p.open()
                    print(f.read(), end='')
                    f.close()

            #Takes user input again to reloop
            input1 = input()
            command = input1[:1]
        #Quits program once while loop ends
        quit()
            
    except:
    #Handles errors, and tells that there is an error and reruns main function to request new input
    #Quits the program if the user used the Q command
        if command=='Q' or command=='q':
            quit()
        print('ERROR')
        run()

if __name__ == '__main__':
    run()