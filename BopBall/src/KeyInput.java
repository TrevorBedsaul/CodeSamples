import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class KeyInput extends KeyAdapter
{
	private Handler handler;

	public KeyInput(Handler handler)
	{
		this.handler = handler;
	}

	public void keyPressed(KeyEvent e)
	{
		int key = e.getKeyCode(); // ASCII value for the letter
		for (int i = 0; i < handler.object.size(); i++)
		{
			GameObject tempObject = handler.object.get(i);
			if (tempObject.getId() == ID.Player)
			{ // key events
				if (!(tempObject.velY == 0 && ((Player) tempObject).getPulse()))
				{
					if (key == KeyEvent.VK_W)
						tempObject.setVelY(-5);
					else if (key == KeyEvent.VK_S)
						tempObject.setVelY(5);
				}
				if(!(tempObject.velX == 0 && ((Player) tempObject).getPulse()))
				{
					if (key == KeyEvent.VK_A)
						tempObject.setVelX(-5);
					else if (key == KeyEvent.VK_D)
						tempObject.setVelX(5);
					else if (key == KeyEvent.VK_SPACE)
						((Player) tempObject).setPulse(true);
				}
			} else if (tempObject.getId() == ID.Player2)
			{ // key events
				if (!(tempObject.velY == 0 && ((Player) tempObject).getPulse()))
				{
					if (key == KeyEvent.VK_UP)
						tempObject.setVelY(-5);
					else if (key == KeyEvent.VK_DOWN)
						tempObject.setVelY(5);
				}
				if(!(tempObject.velX == 0 && ((Player) tempObject).getPulse()))
				{
					if (key == KeyEvent.VK_LEFT)
						tempObject.setVelX(-5);
					else if (key == KeyEvent.VK_RIGHT)
						tempObject.setVelX(5);
					else if (key == KeyEvent.VK_SLASH)
						((Player) tempObject).setPulse(true);
				}
			}
		}
		if (key == KeyEvent.VK_ESCAPE)
		{
			System.exit(1);
		}
	}

	public void keyReleased(KeyEvent e)
	{
		int key = e.getKeyCode();
		for (int i = 0; i < handler.object.size(); i++)
		{
			GameObject tempObject = handler.object.get(i);
			if (tempObject.getId() == ID.Player)
			{ // key events
				if (key == KeyEvent.VK_W)
					tempObject.setVelY(0);
				else if (key == KeyEvent.VK_S)
					tempObject.setVelY(0);
				else if (key == KeyEvent.VK_A)
					tempObject.setVelX(0);
				else if (key == KeyEvent.VK_D)
					tempObject.setVelX(0);
				else if (key == KeyEvent.VK_SPACE)
				{
					((Player) tempObject).setPulse(false);
					((Player) tempObject).pulse();
				}
			} else if (tempObject.getId() == ID.Player2)
			{ // key events
				if (key == KeyEvent.VK_UP)
					tempObject.setVelY(0);
				else if (key == KeyEvent.VK_DOWN)
					tempObject.setVelY(0);
				else if (key == KeyEvent.VK_LEFT)
					tempObject.setVelX(0);
				else if (key == KeyEvent.VK_RIGHT)
					tempObject.setVelX(0);
				else if (key == KeyEvent.VK_SLASH)
				{
					((Player) tempObject).setPulse(false);
					((Player) tempObject).pulse();
				}
			}
		}
	}
}
