import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;

public class Ball extends GameObject
{

	private Handler handler;
	private int tock;

	public Ball(int x, int y, ID id, Handler handler)
	{
		super(x, y, id);
		this.handler = handler;

		velX = 0;
		velY = 0;
	}

	public Rectangle getBounds()
	{
		return new Rectangle(x, y, 12, 12);
	}

	public void tick()
	{
		x += velX;
		y += velY;

		if (y <= 0 || y >= Game.HEIGHT - 48)
			velY *= -1;
		if (x <= 0 || x >= Game.WIDTH - 24)
			velX *= -1;
		handler.addObject(new Trail(x, y, ID.Trail, Color.white, 16, 16, 0.1f, handler));
		for(int i = 0; i < handler.object.size(); i++)
		{
			GameObject tempObject = handler.object.get(i);
			if(tempObject.getId() == ID.Player || tempObject.getId() == ID.Player2)
				if(((Player) (tempObject)).getPulse() == true)
					tock = 0;
			if(tempObject.getId() == ID.Goal)
			{
				Goal goal = (Goal)(tempObject);
				if(this.getBounds().intersects(goal.getPost1Bounds()) || this.getBounds().intersects(goal.getPost3Bounds()))
					{
						if(this.getY() >= goal.getY() - goal.getHeight()/20 && !(this.getY() >= goal.getY() || this.getY() <= goal.getY() + goal.getHeight()))
							velX *= -1;
						else
							velY *= -1;
					}
				else if(this.getBounds().intersects(goal.getPost2Bounds()))
					velX *= -1;
				else if(this.getBounds().intersects(goal.getGoalBounds()))
					goal.goal();
			}
		}
		Game.clamp(velX, -10, 10);
		Game.clamp(velY, -10, 10);
		tock++;
		if(tock >= 100)
		{
			tock = 0;
			if(velX > 0)
				velX--;
			else if(velX < 0)
				velX++;
			if(velY > 0)
				velY--;
			else if(velY < 0)
				velY++;
		}
		
	}

	public void render(Graphics g)
	{
		g.setColor(Color.white);
		g.fillOval(x, y, 12, 12);
	}

	public int getCenterX()
	{
		return x + 6;
	}

		
	public int getCenterY()
	{
		return y + 6;
	}

}
