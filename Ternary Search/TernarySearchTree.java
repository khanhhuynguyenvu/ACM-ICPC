public class TernarySearchTree {
    Node root;
    private TernarySearchTree(){
        this.root = null;
    }
    private Node insert(String key,int pos,Node node){
        char s[] = key.toCharArray();
        if(node == null){
            node = new Node(s[pos],false);
        }
        if(s[pos]<node.data){
            node.left = insert(key,pos,node.left);
        }else if(s[pos]>node.data){
            node.right = insert(key,pos,node.right);
        }else{
            if(pos+1 == key.length()){
                node.isEnd = true;
            }else{
                node.center = insert(key,pos+1,node.center);
            }
        }
        return node;
    }
    public void insert(String key){
        char s[] = key.toCharArray();
        if(key.isEmpty()) throw  new IllegalArgumentException();
        this.root = insert(key,0,this.root);
    }
    public char isExits(){
        return root.data;
    }
    public boolean isContainsKey(String key){
        if(key == null || key.equals("")) throw  new IllegalArgumentException();
        int pos = 0;
        Node node = this.root;
        char s[] = key.toCharArray();
        while (node != null){
            if(s[pos]< node.data){
                node = node.left;
            }else if(s[pos]>node.data){
                node = node.right;
            }else{
                if(++pos == key.length()) return node.isEnd;
                node = node.center;
            }
        }
        return  false;
    }
    public static void main(String[] args) {
        TernarySearchTree tree = new TernarySearchTree();
        tree.insert("AB");
        tree.insert("ABC");
        tree.insert("cat");
        tree.insert("doggy");
        tree.insert("dog");
        System.out.println(tree.isContainsKey("dog"));
    }
}
class Node{
    char data;
    boolean isEnd;
    Node left,center,right;
    public Node(char data, boolean isEnd) {
        this.data = data;
        this.isEnd = isEnd;
        left = right = center = null;
    }
}
