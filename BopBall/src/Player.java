import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

public class Player extends GameObject
{
	private Color color;
	private Handler handler;
	private boolean pulse;
	private int pow, tempPow;
	private int powCount;
	public Player(int x, int y, ID id, Handler handler)
	{
		super(x, y, id);
		this.handler = handler;
		pow = 0;
		if(id == ID.Player)
			color = Color.blue;
		else
			color = Color.orange;
	}

	public Rectangle getBounds()
	{
		return new Rectangle(x, y, 32, 32);
	}

	public Rectangle getRange()
	{
		int tempX = x - 48;
		int tempY = y - 48;
		return new Rectangle(tempX, tempY, 128, 128);
	}
	
	public void tick()
	{
		pow = tempPow;
		if(pulse)
		{
			pow++;
			tempPow = pow;
			if(pow >= 100)
			{
				pow = 100;
			}
			powCount++;
			if(powCount >= 11)
			{
				powCount = 0;
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
		else
		{
			tempPow = 0;
		}
		if(!(pulse && velX == 0))
			x += velX;
		if(!(pulse && velY == 0))
			y += velY;

		x = Game.clamp(x, -16, Game.WIDTH);
		y = Game.clamp(y, -16, Game.HEIGHT - 46);
		
		//handler.addObject(new Trail(x, y, ID.Trail, color, 32, 32, 0.1f, handler));
	}
	
	public boolean getPulse()
	{
		return pulse;
	}
	
	public void setPulse(boolean pulse)
	{
		this.pulse = pulse;
	}
	
	public void pulse()
	{
		for(int i = 0; i < handler.object.size(); i++)
		{
			GameObject tempObject = handler.object.get(i);
			if(tempObject.getId() == ID.Ball)
			{
				if(this.getRange().intersects(tempObject.getBounds()))	//divide by zero error
				{
					if(Math.abs(tempObject.getCenterY() - this.getCenterY()) <= 16)
					{
						if(tempObject.getCenterX() - this.getCenterX() > 0 && tempObject.velX < 0 || tempObject.getCenterX() - this.getCenterX() < 0 && tempObject.getVelX() > 0)
							tempObject.setVelX(0);
						tempObject.setVelX(tempObject.getVelX() + 100/(tempObject.getCenterX() - this.getCenterX()));
						
						if(tempObject.getCenterX() - this.getCenterX() > 0)		//power incorporated
							tempObject.setVelX(tempObject.getVelX() + pow/20);
						else if(tempObject.getCenterX() - this.getCenterX() < 0)
							tempObject.setVelX(tempObject.getVelX() - pow/20);
					}
					else if(Math.abs(tempObject.getCenterX() - this.getCenterX()) <= 16)
					{
						if(tempObject.getCenterY() - this.getCenterY() > 0 && tempObject.velY < 0 || tempObject.getCenterY() - this.getCenterY() < 0 && tempObject.getVelY() > 0)
							tempObject.setVelY(0);
						tempObject.setVelY(tempObject.getVelY() + 100/(tempObject.getCenterY() - this.getCenterY()));
						
						if(tempObject.getCenterY() - this.getCenterY() > 0)		//power incorporated
							tempObject.setVelY(tempObject.getVelY() + pow/20);
						else if(tempObject.getCenterY() - this.getCenterY() < 0)
							tempObject.setVelY(tempObject.getVelY() - pow/20);
					}
					else
					{
						if(tempObject.getCenterY() - this.getCenterY() > 0 && tempObject.velY < 0 || tempObject.getCenterY() - this.getCenterY() < 0 && tempObject.getVelY() > 0)
							tempObject.setVelY(0);
						tempObject.setVelY(tempObject.getVelY() + 100/(tempObject.getCenterY() - this.getCenterY()));
						
						if(tempObject.getCenterY() - this.getCenterY() > 0)		//power incorporated
							tempObject.setVelY(tempObject.getVelY() + pow/20);
						else if(tempObject.getCenterY() - this.getCenterY() < 0)
							tempObject.setVelY(tempObject.getVelY() - pow/20);
						
						
						if(tempObject.getCenterX() - this.getCenterX() > 0 && tempObject.velX < 0 || tempObject.getCenterX() - this.getCenterX() < 0 && tempObject.getVelX() > 0)
							tempObject.setVelX(0);
						tempObject.setVelX(tempObject.getVelX() + 100/(tempObject.getCenterX() - this.getCenterX()));
						
						if(tempObject.getCenterX() - this.getCenterX() > 0)		//power incorporated
							tempObject.setVelX(tempObject.getVelX() + pow/20);
						else if(tempObject.getCenterX() - this.getCenterX() < 0)
							tempObject.setVelX(tempObject.getVelX() - pow/20);
					}
				}
				if(tempObject.velX > 8)
					tempObject.setVelX(8);
				else if(tempObject.velY < -8)
					tempObject.setVelY(-8);
				if(tempObject.velY > 8)
					tempObject.setVelY(8);
				else if(tempObject.velY < -8)
					tempObject.setVelY(-8);
				//Keeps from going too fast
			}
		}
	}
	

	public void render(Graphics g)
	{
		Graphics2D g2d = (Graphics2D)g; g.setColor(Color.green);
		//g2d.draw(getBounds());
		//g2d.draw(getRange());

		if (this.getId() == ID.Player)
		{
			g.setColor(Color.blue);
			g.fillOval(x, y, 32, 32);
		}
		if (this.getId() == ID.Player2)
		{
			g.setColor(Color.orange);
			g.fillOval(x, y, 32, 32);
		}
		if (pulse)
		{
			g.setColor(Color.gray);
			g.fillOval(x, y, 32, 32);
		}
		if (pow >= 100)
		{
			if(powCount%2 == 0)
			{
				g.setColor(Color.white);
				g.fillOval(x, y, 32, 32);
			}
		}
	}

	public int getCenterX()
	{
			return x + 16;
	}

	public int getCenterY()
	{
		return y + 16;
	}

}
