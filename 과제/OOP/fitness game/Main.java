
public class Main {
	
	public static gui gameWindow = new gui(); // ���� GUI
	public static boolean turn = true; // true: ����Ű ���� / false: �Ƶ�ٽ� ����
	public static ��ų[] ��ų�� = {new �ȿ(), new �ٸ��(), new ���ٿ()}; // 3������ ��ų �迭
	public static int ��ųŸ�� = -1; // ��ųŸ���� ����

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Player ����Ű = new Player(100,"����Ű");
		Player �Ƶ�ٽ� = new Player(100,"�Ƶ�ٽ�");
		
		
		gameWindow = new gui(����Ű, �Ƶ�ٽ�);
		gameWindow.setVisible(true);
		
		gameWindow.print("###��Ʈ�Ͻ� ������ �����մϴ�###");
		
		while(true) {
			
			// ���� ���
			if(turn) gameWindow.print("����Ű�� � ����!!");
			else gameWindow.print("�Ƶ�ٽ��� � ����!!");
			
			gameWindow.nameUpdate();
			
			
			// ��ư �Է����� ��ų, ������ ����
			while (��ųŸ�� == -1) {
				for(int i=0; i<gameWindow.btnList.length; i++) {
					if (gameWindow.btnList[i].getModel().isPressed()) break;
					else continue;
				} // ��ư ������ while�� Ż���մϴ�.
			}
			
			if(��ųŸ�� == 3) { // ������ ���: �ڽ��� HP ȸ��
				gameWindow.print("�������� ����մϴ�!");
				if(turn) ����Ű.���();
				else �Ƶ�ٽ�.���();
				
			} else { // ��ų ���: ��븦 ����
				gameWindow.print(��ų��[��ųŸ��].��ų�̸� + "�� �����߽��ϴ�!");
			
				if(turn) ����Ű.�(��ų��[��ųŸ��], �Ƶ�ٽ�);
				else �Ƶ�ٽ�.�(��ų��[��ųŸ��], ����Ű);
			}
			
			gameWindow.update();
			gameWindow.print("------------------------------");
			
			// ���ӿ������� Ȯ��
			if (����Ű.hp() == 0 || �Ƶ�ٽ�.hp() == 0) break;
			
			// 1�� ���
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			// ���� ���ʷ� �Ѿ��
			if (turn) turn = false;
			else turn = true;
			��ųŸ�� = -1; // �ʱ�ȭ
			
		} // ���� ���� ��
		
		gameWindow.print("���� ����!!");
		
		if (����Ű.hp() == 0 && �Ƶ�ٽ�.hp() != 0) gameWindow.print("�Ƶ�ٽ��� �̰���ϴ�.");
		else if (����Ű.hp() != 0 && �Ƶ�ٽ�.hp() == 0) gameWindow.print("����Ű�� �̰���ϴ�.");
		else gameWindow.print("�����ϴ�.");
		
		gameWindow.saveLog();
		

	}

}
