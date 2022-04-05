

def userInput():
    ipFile = open('input1.txt','w')
    print("Enter the Choice : ")
    print("i- A or a for Ascending Order!")
    print("ii- D or d for Descending Order!")
    print("iii- N or n for new Sequence!")
    print("iv- X or x to end input prompt")
    ip=[]
    x = input()
    if x == 'A' or x=='a':
        ip.append(x)
        while x!='n' and x!='N' and x!='x' and x!='X':
            x = input("Please enter a number OR \n Enter N for new sequence OR \n Enter X to end input prompt \n")
            ip.append(x)
            if x == 'N' or x =='n':
                for i in range(len(ip)):
                    ipFile.write(ip[i])
                    if i == len(ip) - 1:
                        ipFile.write('\n')
                    else:
                        ipFile.write(' ')
                userInput()
    elif x =='x' or x=="X":
        return "Exiting!"

    print(ip)
#userInput()'''

def sortOutput(key, ip):
    if key == 'A' or key == 'a':
        for i in range(len(ip)):
            for j in range(i + 1, len(ip)):
                if int(ip[i]) > int(ip[j]):
                    temp = ip[i]
                    ip[i] = ip[j]
                    ip[j] = temp
        return ip
    elif key == 'D' or key == 'd':
        for i in range(len(ip)):
            for j in range(i + 1, len(ip)):
                if int(ip[i]) < int(ip[j]):
                    temp = ip[i]
                    ip[i] = ip[j]
                    ip[j] = temp
        return ip
    else:
        return "Wrong Input"


def main():
    with open('input.txt', 'r') as ipFile:
        opFile = open('result.txt', 'w')
        while True:
            line = ipFile.readline().replace("\n", " ")
            if line:
                ip = line.split(" ")
                sortType = ip.pop(0)
                ip.pop(len(ip) - 1)
                result = sortOutput(sortType, ip)
                opFile.write(sortType)
                opFile.write(' ')
                for i in range(len(result)):
                    opFile.write(result[i])
                    if i == len(result) - 1:
                        opFile.write('\n')
                    else:
                        opFile.write(' ')
            else:
                ipFile.close()
                opFile.close()
                break

def oracle():
    observed = open('result.txt','r')
    expected = open('expected.txt','r')
    log = open('logfile.txt','w')

    i=1
    count=0
    while True:
        exp = expected.readline().replace('\n','')
        obs = observed.readline().replace('\n','')
        if exp and obs:
            if exp == obs:
                v = "Test Case : "+repr(i)+" -> True "+ " "+ "Expected : " +repr(exp)+" <-> "+" Oberserved : "+repr(obs)+'\n'
                log.write(v)
                count+=1
            else:
                log.write("Test Case : " + repr(i) + " -> False " + " " + "Expected : " + repr(
                    exp) + " <-> " + " Oberserved : " + repr(obs) + '\n')
        else:
            expected.close()
            observed.close()
            log.close()
            break
        i+=1

main()
oracle()
print("Operations Performed ! Please Check the Log file !")

