package DataStructures;

import java.util.ArrayList;

public class LinkedList {
    public static void main(String[] args){
        node n = new node();

    }


    static class node{
        int val;
        node next;

        node(){}

        node(int x){ this.val = x; }

        node(int x, node n){
            this.val = x;
            this.next = n;
        }
    }

}
