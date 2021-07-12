max = 10
top = -1

def create_stack():
    stack = []
    return stack

def check_empty(stack):
    return len(stack) == 0

def push(stack, item):
    stack.append(item)
    print("pushed item: " + item)

def pop(stack):
    if (check_empty(stack)):
        return "stack is empty"

    return stack.pop()


stack = create_stack()

push(stack, str(1))
push(stack, str(2))
push(stack, str(3))
push(stack, str(4))
push(stack, str(5))
push(stack, str(6))
push(stack, str(7))
push(stack, str(8))
push(stack, str(9))

print(str(stack))

temp1=pop(stack)
temp2=pop(stack)
temp3=pop(stack)
temp4=pop(stack)
temp5=pop(stack)
temp6=pop(stack)
temp7=pop(stack)
temp8=pop(stack)
temp9=pop(stack)

temp=[temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9]

print(temp)

