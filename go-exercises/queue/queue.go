package queue

import "fmt"

type Node struct {
	data int
	next *Node
}

type Queue struct {
	front *Node
	rear  *Node
}

/* func (Q *Queue) InitQueue() {
	Q.front = nil
	Q.rear = nil
} */

func (Q *Queue) Enqueue(data int) {
	temp := &Node{
		next: nil,
		data: data,
	}

	if Q.front == nil {
		Q.front = temp
		Q.rear = temp

		return
	}

	Q.rear.next = temp
	Q.rear = Q.rear.next
}

func (Q *Queue) Dequeue() {
	if Q.front == nil {
		fmt.Println("Queue is empty")

		return
	}

	Q.front = Q.front.next
}
