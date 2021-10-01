from queue import LifoQueue

stack = LifoQueue(maxsize = 3)
print("Size: ", stack.qsize())

stack.put("a")
stack.put("b")
stack.put("c")
 
print("Full: ", stack.full())
print("Size: ", stack.qsize())

print("\nPopping 1 Element: ")
print("Popped: ", stack.get())

print("\nPopping 2 Elements: ")
print("Popped: ", stack.get())
print("Popped: ", stack.get())

print("\nEmpty: ", stack.empty())