import java.util.Scanner;

class LinkedList
{
	private Node head;
	public LinkedList() {head = null;}
	public void AddNode(int data)
	{
		Node n = new Node(data);
		n.next = head;
		head = n;
	}
	public void Remove(int data)
	{
		if (head == null)
			return;
		while (head.data == data)
			head = head.next;
		Node temp = head.next;
		Node pre = head;
		while (temp != null)
		{
			if (temp.data == data)
				pre.next = temp.next;
			else
				pre = temp;
			temp = temp.next;
		}
	}
	public void Print()
	{
		Node temp = head;
		while (temp != null)
		{
			System.out.println(temp.toString());
			temp = temp.next;
		}
	}
	private class Node
	{
		public int data;
		public Node next;
		public Node(int data) {this.data = data;next = null;}
		public String toString() {return "(" + data + ")";}
	}
	public static void main(String[] args)
	{
		String s;
		double d;
		Scanner sc = new Scanner(System.in);
		s = sc.next();
		System.out.print(s);
		d = sc.nextDouble();
		System.out.print(d);
		LinkedList l = new LinkedList();
		for (int i = 0; i < 10; i++)
			l.AddNode(i);	
		l.AddNode(1);
		l.AddNode(5);
		l.AddNode(5);
		l.AddNode(1);
		System.out.println("Initial...");
		l.Print();
		l.Remove(1);
		System.out.println("Remove 1...");
		l.Print();
		l.Remove(5);
		System.out.println("Remove 5...");
		l.Print();
	}
}
