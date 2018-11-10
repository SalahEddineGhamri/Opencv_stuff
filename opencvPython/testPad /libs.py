import params

x = &(params.y)

def changeX():
    global x 
    print "X is ", x
    x += 1 
    return x

def setx(var):
    global x
    x = var
