from sys import stdin, stdout, exit

def readLine():
	return stdin.readline().strip()

def readInt():
	return int(readLine())

def readInts():
	return list(map(int, readLine().split()))

def printLine(line):  
    print(line)
    stdout.flush()
    
# py -2 interactive_runner.py py -2 testing_tool.py 0 -- py -2 DatBae.py

def main():
    t = readInt()        
    n, b, f = readInts()  
    printLine('1 2 3')
    veredict = readInt()
 
    n, b, f = readInts()  
    printLine('2 3 5')
    veredict = readInt()

    n, b, f = readInts()
    printLine('1000')
    veredict = readInt()
    exit(0)

if __name__ == '__main__':
	main()
