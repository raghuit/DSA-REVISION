class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def display(self):
        node = self.head
        while node:
            print(str(node.data) + " -> ", end = "")
            node = node.next
        print("END")

    def printMiddle(self):
        slow = self.head
        fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        print("Middle Value: ", slow.data)


if __name__=='__main__':
    linkedList = LinkedList()
    flag = 1
    while flag != 0:
        n = int(input("Enter Element to be Inserted: "))
        linkedList.push(n)
        flag = int(input("Continue? (1/0): "))
    linkedList.display()
    linkedList.printMiddle()