import java.util.Stack;

public class Player implements Workable, Usable {
    
	private int hp;
    public String name;
    private Stack<아이템> 가방 = new Stack<>();
    
    public Player(int hp, String name) {
		super();
		this.hp = hp;
		this.name = name;
		
		for(int i = 0; i < 3; i++) 가방.add(new 스무디());
	}
    
    public int hp() {
    	return this.hp;
    }
    
    public void hp깎기 (int 대미지) {
    	this.hp -= 대미지;
    	Main.gameWindow.print("- "+name+"의 hp가 "+대미지+"만큼 깎였습니다.");
    	if(this.hp < 0) this.hp = 0;
    	Main.gameWindow.print("- "+name+"의 hp: "+this.hp);
    }
    
    public void hp회복 (int 회복량) {
    	this.hp += 회복량;
    	System.out.println("- "+name+"의 hp가 "+회복량+"만큼 회복되었습니다.");
    	Main.gameWindow.print("- "+name+"의 hp가 "+회복량+"만큼 회복되었습니다.");
    	if(this.hp > 100) this.hp = 100;
    	System.out.println("- "+name+"의 hp: "+this.hp);
    	Main.gameWindow.print("- "+name+"의 hp: "+this.hp);
    }
    
	@Override
	public void 사용() {
		// TODO Auto-generated method stub
		if(가방.size() > 0) {
			가방.pop().사용(this);
		} else {
			Main.gameWindow.print("사용할 수 있는 아이템이 없습니다.");
		}
	}
	
	@Override
	public void 운동(스킬 타입, Player 타겟) {
		// TODO Auto-generated method stub
		int 피격 = 타입.대미지출력();
		타겟.hp깎기(피격);
	}
    
}
