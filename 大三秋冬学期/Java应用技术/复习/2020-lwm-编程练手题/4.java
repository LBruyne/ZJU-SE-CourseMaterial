enum LogicalOp {
    and, or;

    boolean test(boolean p1, boolean p2) {
        if(this == and) {
            return p1 && p2;
        }
        else if(this == or){
            return p1 || p2;
        }
        else {
            return false;
        }
    };
}