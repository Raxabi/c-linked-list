package ll

type Node[T any] struct {
	Data T
	Next *Node[T]
}

func N_New[T any](data T) Node[T] {
	return Node[T]{
		Data: data,
		Next: nil,
	}
}
