while True:
    try:
        x, a, y, b =  map(int, raw_input().split()) 
        if(x * b > y * a):
            print(">")
        elif(x * b < y * a):
            print("<")
        else:
            print("=")
    except:
        break