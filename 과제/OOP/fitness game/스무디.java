public class 스무디 extends 아이템 implements Healable {
	
	public 스무디() {
		super(10, "회복");
	}
	
	@Override
	public void 사용(Player 타겟) {
		// TODO Auto-generated method stub
		회복(타겟);
	}

	@Override
	public void 회복(Player 타겟) {
		// TODO Auto-generated method stub
		타겟.hp회복(효율);
	}

}
