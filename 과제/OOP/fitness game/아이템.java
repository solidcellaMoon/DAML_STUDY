public abstract class 아이템 {
    protected int 효율;
    protected String 효과;
    
    아이템 () {
    	// Do Something
    }
    
    아이템(int 효율, String 효과내용) {
    	this.효율 = 효율;
    	String 효과 = 효과내용;
    }
    
    public abstract void 사용(Player 타겟);

}
