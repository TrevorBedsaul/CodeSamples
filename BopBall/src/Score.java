import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;

public class Score extends GameObject
{

	private Handler handler;
	
	public Score(int x, int y, ID id, Handler handler)
	{
		super(x, y, id);
		this.handler = handler;
		velX = -12;
	}

	public void tick()
	{
		x += velX;
	}

	public void render(Graphics g)
	{
		Font tempF = g.getFont();
		Color tempC = g.getColor();
		g.setFont(new Font("Times New Roman", Font.BOLD, 250));
		g.setColor(new Color((int)(Math.random()*256), (int)(Math.random()*256), (int)(Math.random()*256) ));
		g.drawString("GOOOAAALLLLL", x + 1000, 320);
		g.setFont(tempF);
		g.setColor(tempC);
	}

	public Rectangle getBounds()
	{
		return null;
	}

	public int getCenterX()
	{
		return 0;
	}

	public int getCenterY()
	{
		return 0;
	}

}
