package queue

import (
	"testing"
)

func TestEnqueue(t *testing.T) {
	queue := Queue{}
	queue.Enqueue(5)
	queue.Enqueue(3)

	expected := 5

	actual := queue.front.data

	if actual != expected {
		t.Errorf("Got %v expected %v", actual, expected)
	}
}

func TestDequeue(t *testing.T) {
	queue := Queue{}
	queue.Enqueue(5)
	queue.Enqueue(3)
	queue.Dequeue()

	expected := 3

	actual := queue.front.data

	if actual != expected {
		t.Errorf("Got %v expected %v", actual, expected)
	}
}
