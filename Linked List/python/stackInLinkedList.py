class Node:
	def __init__(self,data):
		self.data = data
		self.next = None
	
class Stack:
    def __init__(self):
        self.head = None

    def isempty(self):
        if self.head == None:
            return True
        else:
            return False
	
    def push(self,data):	
        if self.head == None:
            self.head=Node(data)
        else:
            newnode = Node(data)
            newnode.next = self.head
            self.head = newnode

    def pop(self):
        if self.isempty():
            return None
        else:
            poppednode = self.head
            self.head = self.head.next
            poppednode.next = None
            return poppednode.data

    def peek(self):
        if self.isempty():
            return None
        else:
            return self.head.data

    def display(self):
        iternode = self.head
        if self.isempty():
            print("Stack Underflow")
        else:
            while(iternode != None):
                print(iternode.data,"->",end = " ")
                iternode = iternode.next
            print("END")
            return

MyStack = Stack()

MyStack.push("a")
MyStack.push("b")
MyStack.push("c")
MyStack.push("d")

MyStack.display()

print("Top of Stack: ", MyStack.peek())

print("Popped: ", MyStack.pop())
print("Popped: ", MyStack.pop())
MyStack.display()

print("Top of Stack: ", MyStack.peek())