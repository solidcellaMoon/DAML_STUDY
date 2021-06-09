public class 스킬 {
    
	private int 대미지;
    private int 세트;
    private int 쿨타임;
    public String 스킬이름;
    
    public 스킬(int 대미지, int 쿨타임) {
		super();
		this.대미지 = 대미지;
		this.쿨타임 = 쿨타임;
	}
    
    public int 대미지출력() {
    	System.out.println(this.스킬이름+"을 시전했습니다!");
    	return 대미지;
    }

}
