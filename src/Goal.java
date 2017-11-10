import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;

public class Goal extends GameObject
{

	private Handler handler;
	private int width, height;
	private Rectangle post1, post2, post3;
	private boolean left;
	private static boolean goal;
	private static int tock;
	private Spawn spawner;
	
	public Goal(int x, int y, int width, int height, boolean left, Spawn spawner, ID id, Handler handler)
	{
		super(x, y, id);
		this.width = width;
		this.height = height;
		this.handler = handler;
		this.left = left;
		this.spawner = spawner;
		post1 = new Rectangle(x, y, width, height/20);
		if(left)
			post2 = new Rectangle(x, y, height/20, height);
		else
			post2 = new Rectangle(x + width - height/20, y, height/20, height);
		post3 = new Rectangle(x, y + height - height/20, width, height/20);
	}

	public void tick()
	{
		if(tock >= 500)
		{
			tock = 0;
			goal = false;
			spawner.reset();
		}
		else if(goal)
			tock++;
	}

	public void render(Graphics g)
	{
		g.setColor(Color.white);
		g.fillRect(x, y, width, height/20);
		if(left)
			g.fillRect(x, y, height/20, height);
		else
			g.fillRect(x + width - height/20, y, height/20, height);
		g.fillRect(x, y + height - height/20, width, height/20);
		g.setColor(Color.gray);
		for(int i = 0; i <= width - 10; i = i + 10)
		{
			g.drawLine(x + i, y, x + width, y + height - i);
			g.drawLine(x + i, y + height, x + width, y + i);
			g.drawLine(x, y + i, x + width - i, y + height);
			g.drawLine(x + width - i, y, x, y + height - i);
		}
	}
	
	public Rectangle getBounds()
	{
		return new Rectangle(x - 1, y - 1, width + 2, height + 2);
	}
	
	public Rectangle getGoalBounds()
	{
		if(left)
			return new Rectangle(x, y + 12, width - 12, height - 24);
		return new Rectangle(x + 12, y +12, width - 24, height - 24);
	}
	
	
	public Rectangle getPost1Bounds()
	{
		return post1;
	}
	
	public Rectangle getPost2Bounds()
	{
		return post2;
	}
	
	public Rectangle getPost3Bounds()
	{
		return post3;
	}

	public int getCenterX()
	{
		return 0;
	}

	public int getCenterY()
	{
		return 0;
	}
	
	public int getWidth()
	{
		return width;
	}
	
	public int getHeight()
	{
		return height;
	}

	public boolean getLeft()
	{
		return left;
	}
	
	public void goal()
	{
		goal = true;
		if(tock == 0)
		{
			HUD.goal(left);
			handler.addObject(new Score(0, 200, ID.Score, handler));
			handler.addObject(new Score(-1, 200, ID.Score, handler));
			handler.addObject(new Score(-2, 200, ID.Score, handler));
			handler.addObject(new Score(-3, 200, ID.Score, handler));
		}
		
	}
	
}
