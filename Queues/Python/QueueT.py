queue = []

queue.append("a")
queue.append("b")
queue.append("c")
 
print("Queue: ", end = "")
print(queue)

print("\nPopping 1 Element: ")
print("Popped: ", queue.pop(0))
print("Queue: ", end = "")
print(queue)

print("\nPopping 2 Elements: ")
print("Popped: ", queue.pop(0))
print("Popped: ", queue.pop(0))
print("Queue: ", end = "")
print(queue)
