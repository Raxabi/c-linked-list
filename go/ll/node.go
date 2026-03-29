package ll

type Node[T any] struct {
	idx  int
	Data T
	Next *Node[T]
}

func N_New[T any](idx int, data T) Node[T] {
	return Node[T]{
		idx:  idx,
		Data: data,
		Next: nil,
	}
}
