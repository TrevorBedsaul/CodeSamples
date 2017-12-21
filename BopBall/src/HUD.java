import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class HUD
{
	public static int SCORE_P1 = 0;	//Not good for multiple players
	public static int SCORE_P2 = 0;
	private static int tock;
	
	public void tick()
	{
		
	}
	
	public void render(Graphics g)
	{
		Color temp = g.getColor();
		g.setColor(Color.WHITE);
		g.drawString("BopBall!", 10, 20);
		g.setFont(new Font("Times New Roman", Font.PLAIN, 80));
		g.drawString("Score: " + SCORE_P1  + " - " + SCORE_P2, 120, 80);
		g.setColor(temp);
	}
	
	public static void goal(boolean left)
	{
		if(left)
			SCORE_P2++;
		else
			SCORE_P1++;
		
	}
}
