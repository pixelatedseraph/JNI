public class LinkedListJNI{
    private linkedList<Object> list = new linkedList<>();

    public void Jinsert(Object data){
        list.insertBack(data);
    }

    public void Jprint(){
        list.printList();
    }

   // public native void nativeHello();

    static {
       // System.loadLibrary("jnitest");
    }
}