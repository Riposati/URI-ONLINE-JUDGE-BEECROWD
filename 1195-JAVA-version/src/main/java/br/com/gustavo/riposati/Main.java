package br.com.gustavo.riposati;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node{
    int key;
    Node left;
    Node right;

    public Node(int key){
        this.key = key;
    }
}

class Tree {
    Node root;
    static int flag=0;
    static int biggest =0;

    Node insertNode(int key, Node root) {

        if (root == null) {
            root = new Node(key);
        } else {

            if (root.key < key) {
                root.right = insertNode(key,root.right);
            } else if(root.key > key)
                root.left = insertNode(key,root.left);
        }
        return root;
    }
    void inOrder(Node root){
        if(root!=null){
            if(root.key== biggest){
                inOrder(root.left);
                System.out.print(root.key);
                inOrder(root.right);

            }else{
                inOrder(root.left);
                System.out.print(root.key + " ");
                inOrder(root.right);
            }
        }
    }

    static void preOrder(Node root){
        if(root!=null) {
            if (flag == 0) {
                System.out.print(root.key);
                flag = 1;
            } else {
                System.out.print(" " + root.key);
            }
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    void postOrder(Node root,Node keepRoot){

        if(root!=null){
            if(root.key==keepRoot.key){
                postOrder(root.left,keepRoot);
                postOrder(root.right,keepRoot);
                System.out.print(root.key);
            }else{
                postOrder(root.left,keepRoot);
                postOrder(root.right,keepRoot);
                System.out.print(root.key + " ");
            }
        }
    }
    void searchNode(int key,Node root){
        Node node = root;

        while(node != null && node.key != key){

            if(node.key > key)
                node = node.left;
            else
                node = node.right;
        }

        if (node != null) {
            System.out.println(key + " existe");
        }else {
            System.out.println(key + " nao existe");
        }
    }

    Node removeNode(int key,Node root){

        if(root==null){
            return null;
        }

        if (root.key < key) {
            root.right = removeNode(key, root.right);
        } else if (root.key > key)
            root.left = removeNode(key, root.left);

        else {

            if(root.left == null && root.right == null)

                root = null;

            else if (root.left == null)

                root = root.right;

            else if (root.right == null)

                root = root.left;

            else {

                Node rootAux = root.left;

                while (rootAux.right != null) {
                    rootAux = rootAux.right;
                }
                int rootOldKey = root.key;
                root.key = rootAux.key;
                rootAux.key = rootOldKey;
                root.left = removeNode(rootOldKey,root.left);
            }
        }

        return root;
    }
    int treeMaximum(Node root){

        while(root.right != null){

            root = root.right;
        }
        return root.key;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {

        Tree tree = new Tree();
        InputStreamReader ir = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(ir);
        String keys= "";

        while ((keys = in.readLine()) != null && keys.length() != 0) {

            String[] keyAux = keys.split(" ");

            if (keyAux.length == 1) {

                switch(keyAux[0]){

                    case "INFIXA":
                        Tree.biggest = tree.treeMaximum(tree.root);
                        tree.inOrder(tree.root);
                        System.out.print("\n");
                        break;

                    case "PREFIXA":
                        Tree.preOrder(tree.root);
                        Tree.flag = 0;
                        System.out.print("\n");
                        break;

                    case "POSFIXA":
                        tree.postOrder(tree.root, tree.root);
                        System.out.print("\n");
                        break;

                    default:
                        break;
                }

            } else {

                if (keyAux[0].equals("I")) {
                    tree.root = tree.insertNode(Integer.parseInt(keyAux[1]), tree.root);
                } else if (keyAux[0].equals("P")) {
                    tree.searchNode(Integer.parseInt(keyAux[1]), tree.root);
                } else if (keyAux[0].equals("R")) {
                    tree.root = tree.removeNode(Integer.parseInt(keyAux[1]), tree.root);
                }
            }
        }
    }
}