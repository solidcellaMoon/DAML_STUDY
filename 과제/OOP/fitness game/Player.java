import java.util.Stack;

public class Player implements Workable, Usable {
    
	private int hp;
    public String name;
    private Stack<������> ���� = new Stack<>();
    
    public Player(int hp, String name) {
		super();
		this.hp = hp;
		this.name = name;
		
		for(int i = 0; i < 3; i++) ����.add(new ������());
	}
    
    public int hp() {
    	return this.hp;
    }
    
    public void hp��� (int �����) {
    	this.hp -= �����;
    	Main.gameWindow.print("- "+name+"�� hp�� "+�����+"��ŭ �𿴽��ϴ�.");
    	if(this.hp < 0) this.hp = 0;
    	Main.gameWindow.print("- "+name+"�� hp: "+this.hp);
    }
    
    public void hpȸ�� (int ȸ����) {
    	this.hp += ȸ����;
    	System.out.println("- "+name+"�� hp�� "+ȸ����+"��ŭ ȸ���Ǿ����ϴ�.");
    	Main.gameWindow.print("- "+name+"�� hp�� "+ȸ����+"��ŭ ȸ���Ǿ����ϴ�.");
    	if(this.hp > 100) this.hp = 100;
    	System.out.println("- "+name+"�� hp: "+this.hp);
    	Main.gameWindow.print("- "+name+"�� hp: "+this.hp);
    }
    
	@Override
	public void ���() {
		// TODO Auto-generated method stub
		if(����.size() > 0) {
			����.pop().���(this);
		} else {
			Main.gameWindow.print("����� �� �ִ� �������� �����ϴ�.");
		}
	}
	
	@Override
	public void �(��ų Ÿ��, Player Ÿ��) {
		// TODO Auto-generated method stub
		int �ǰ� = Ÿ��.��������();
		Ÿ��.hp���(�ǰ�);
	}
    
}
