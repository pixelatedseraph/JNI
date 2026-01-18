class Node<T>{
    T       data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

public class linkedList<T>{
    private Node<T> head = null;

    public void insertBack(T data){
        Node<T> n = new Node<>(data);
        if( head == null ){
            head = n;
        }
        else {
            Node<T> tmp = head;
            while(tmp.next != null){
                tmp = tmp.next;
            }
            tmp.next = n;
        }
    }

    public void printList(){
        Node<T> tmp = head;
        while (tmp != null ) { 
            System.out.println(tmp.data);
            tmp = tmp.next;
        }
      
    }


    public static void main(String[] args) {
        linkedList<String> l1 = new linkedList<>();
        linkedList<Integer> l2 = new linkedList<>();

        l1.insertBack("mazeed");
        l1.insertBack("faizan");
        l1.insertBack("kowshik");

        l2.insertBack(10);
        l2.insertBack(20);
        l2.insertBack(30);
        

        l1.printList();
        l2.printList();
    }
}

