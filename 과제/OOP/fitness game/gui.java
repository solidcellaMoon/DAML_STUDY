import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JProgressBar;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JTextField;
import java.awt.Color;
import javax.swing.JTextArea;
import javax.swing.JToggleButton;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;

import java.awt.SystemColor;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class gui extends JFrame {
	
	private Player pN, pA;

	private JPanel contentPane;
	private JProgressBar pBar_N;
	private JProgressBar pBar_A;
	private JLabel title;
	private JLabel name_N;
	private JLabel name_A;
	private JScrollPane scrPane;
	private JTextArea textArea;
	
	
	//private JButton skillBtn1;
	//private JButton skillBtn2;
	//private JButton skillBtn3;
	//private JButton itemBtn;
	
	public JButton[] btnList = new JButton[4];
	private JButton btnNewButton;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					gui frame = new gui();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public gui() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 573, 564);
		contentPane = new JPanel();
		contentPane.setBackground(SystemColor.inactiveCaptionBorder);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		pBar_N = new JProgressBar();
		pBar_N.setValue(100);
		pBar_N.setBackground(Color.WHITE);
		pBar_N.setForeground(SystemColor.textHighlight);
		pBar_N.setBounds(12, 335, 228, 47);
		contentPane.add(pBar_N);
		
		pBar_A = new JProgressBar();
		pBar_A.setForeground(SystemColor.textHighlight);
		pBar_A.setValue(100);
		pBar_A.setBackground(Color.WHITE);
		pBar_A.setBounds(303, 335, 242, 47);
		contentPane.add(pBar_A);
		
		title = new JLabel("피트니스 게임");
		title.setHorizontalAlignment(SwingConstants.CENTER);
		title.setFont(new Font("나눔고딕 ExtraBold", Font.PLAIN, 20));
		title.setBounds(204, 10, 158, 47);
		contentPane.add(title);
		
		name_N = new JLabel("나이키");
		name_N.setHorizontalAlignment(SwingConstants.CENTER);
		name_N.setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		name_N.setBounds(71, 297, 111, 28);
		contentPane.add(name_N);
		
		name_A = new JLabel("아디다스");
		name_A.setHorizontalAlignment(SwingConstants.CENTER);
		name_A.setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		name_A.setBounds(369, 297, 111, 28);
		contentPane.add(name_A);
		
		textArea = new JTextArea();
		textArea.setBounds(83, 67, 397, 217);
		scrPane = new JScrollPane(textArea);
		scrPane.setBounds(83, 67, 397, 217);
		contentPane.add(scrPane);
		
		btnList[0] = new JButton("\uD314\uC6B4\uB3D9");
		btnList[0].setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		btnList[0].setBounds(17, 422, 111, 61);
		contentPane.add(btnList[0]);
		
		btnList[1] = new JButton("\uB2E4\uB9AC\uC6B4\uB3D9");
		btnList[1].setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		btnList[1].setBounds(150, 422, 111, 61);
		contentPane.add(btnList[1]);
		
		btnList[2] = new JButton("\uBCF5\uADFC\uC6B4\uB3D9");
		btnList[2].setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		btnList[2].setBounds(285, 422, 111, 61);
		contentPane.add(btnList[2]);
		
		btnList[3] = new JButton("\uD68C\uBCF5\uC544\uC774\uD15C");
		btnList[3].setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		btnList[3].setBounds(416, 422, 111, 61);
		contentPane.add(btnList[3]);

	}
	
	public gui(Player pN, Player pA) {
		
		this();
		this.pN = pN;
		this.pA = pA;
		
		update();
		
		//pBar_N.setValue(pN.hp());
		//pBar_A.setValue(pA.hp());
		
		btnList[0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Main.스킬타입 = 0;
				System.out.print(Main.스킬타입);
			}
		});
		
		btnList[1].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Main.스킬타입 = 1;
				System.out.print(Main.스킬타입);
			}
		});
		
		btnList[2].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Main.스킬타입 = 2;
				System.out.print(Main.스킬타입);
			}
		});
		
		btnList[3].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Main.스킬타입 = 3;
				System.out.print(Main.스킬타입);
			}
		});
		
		
	}
	
	public void update() {
		if (pN != null && pA != null) {
			pBar_N.setValue(pN.hp());
			pBar_A.setValue(pA.hp());
		}
	}
	
	public void nameUpdate() {
		if(Main.turn) {
			name_N.setFont(new Font("나눔바른고딕", Font.BOLD, 15));
			name_N.setForeground(Color.MAGENTA);
			name_A.setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
			name_A.setForeground(Color.BLACK);
		} else {
			name_A.setFont(new Font("나눔바른고딕", Font.BOLD, 15));
			name_A.setForeground(Color.MAGENTA);
			name_N.setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
			name_N.setForeground(Color.BLACK);
		}
	}
	
	public void print(String str) {
		textArea.append(str+"\n");
		textArea.setCaretPosition(textArea.getDocument().getLength());  // 맨아래로 스크롤한다.
	}
	
	public void saveLog() {
		File f = new File("C:\\Users\\user\\Desktop\\test.log");
		try {
			PrintWriter pw = new PrintWriter(f);
			pw.write(textArea.getText());
			pw.close();
			print("게임 로그가 저장되었습니다.");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			print("저장에 실패했습니다.");
		}
	}
}
