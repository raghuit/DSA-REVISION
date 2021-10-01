stack = []

stack.append("a")
stack.append("b")
stack.append("c")
 
print("Stack: ", end = "")
print(stack)

print("\nPopping 1 Element: ")
print("Popped: ", stack.pop())
print("Stack: ", end = "")
print(stack)

print("\nPopping 2 Elements: ")
print("Popped: ", stack.pop())
print("Popped: ", stack.pop())
print("Stack: ", end = "")
print(stack)