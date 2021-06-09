
public class Main {
	
	public static gui gameWindow = new gui(); // 게임 GUI
	public static boolean turn = true; // true: 나이키 공격 / false: 아디다스 공격
	public static 스킬[] 스킬셋 = {new 팔운동(), new 다리운동(), new 복근운동()}; // 3종류의 스킬 배열
	public static int 스킬타입 = -1; // 스킬타입을 저장

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Player 나이키 = new Player(100,"나이키");
		Player 아디다스 = new Player(100,"아디다스");
		
		
		gameWindow = new gui(나이키, 아디다스);
		gameWindow.setVisible(true);
		
		gameWindow.print("###피트니스 게임을 시작합니다###");
		
		while(true) {
			
			// 차례 출력
			if(turn) gameWindow.print("나이키의 운동 차례!!");
			else gameWindow.print("아디다스의 운동 차례!!");
			
			gameWindow.nameUpdate();
			
			
			// 버튼 입력으로 스킬, 아이템 선택
			while (스킬타입 == -1) {
				for(int i=0; i<gameWindow.btnList.length; i++) {
					if (gameWindow.btnList[i].getModel().isPressed()) break;
					else continue;
				} // 버튼 누르면 while문 탈출합니다.
			}
			
			if(스킬타입 == 3) { // 아이템 사용: 자신의 HP 회복
				gameWindow.print("아이템을 사용합니다!");
				if(turn) 나이키.사용();
				else 아디다스.사용();
				
			} else { // 스킬 사용: 상대를 공격
				gameWindow.print(스킬셋[스킬타입].스킬이름 + "을 시전했습니다!");
			
				if(turn) 나이키.운동(스킬셋[스킬타입], 아디다스);
				else 아디다스.운동(스킬셋[스킬타입], 나이키);
			}
			
			gameWindow.update();
			gameWindow.print("------------------------------");
			
			// 게임오버인지 확인
			if (나이키.hp() == 0 || 아디다스.hp() == 0) break;
			
			// 1초 대기
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			// 다음 차례로 넘어가기
			if (turn) turn = false;
			else turn = true;
			스킬타입 = -1; // 초기화
			
		} // 게임 진행 끝
		
		gameWindow.print("게임 종료!!");
		
		if (나이키.hp() == 0 && 아디다스.hp() != 0) gameWindow.print("아디다스가 이겼습니다.");
		else if (나이키.hp() != 0 && 아디다스.hp() == 0) gameWindow.print("나이키가 이겼습니다.");
		else gameWindow.print("비겼습니다.");
		
		gameWindow.saveLog();
		

	}

}
