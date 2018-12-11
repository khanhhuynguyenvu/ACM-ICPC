public class TernarySearchTree {
    private Node root;
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
    private void insert(String key){
        if(key.isEmpty()) throw  new IllegalArgumentException();
        this.root = insert(key,0,this.root);
    }
    private boolean isContainsKey(String key){
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
    private void isContainsKey(String key,TernarySearchTree tree){
        System.out.println("Key word : "+key+" is "+(tree.isContainsKey(key)?"found!":"not found!"));
    }
    private void TraverseTST(Node node,char res[],int depth){
        if(node != null){
            TraverseTST(node.left,res,depth);
            res[depth] = node.data;
            if(node.isEnd){
                for(int i = 0 ; i < depth+1;i++){
                    System.out.print(res[i]);
                }
                System.out.println();
            }
            TraverseTST(node.center,res,depth+1);
            TraverseTST(node.right,res,depth);
        }
    }
    private void TraverseTST(){
        int Max = 1000;
        char temp[] = new char[Max];
        System.out.println("Traverse ternary search tree: ");
        TraverseTST(this.root,temp,0);
    }
    public static void main(String[] args) {
        TernarySearchTree tree = new TernarySearchTree();
        tree.insert("An");
        tree.insert("Tung");
        tree.insert("Binh");
        tree.insert("Lee");
        tree.insert("Vy");
        tree.insert("Nhat");
        tree.isContainsKey("Ans",tree);
        tree.TraverseTST();
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
