
public class Spawn
{
	private Handler handler;
	private HUD hud;
	
	public Spawn(Handler handler, HUD hud)
	{
		this.handler = handler;
		this.hud = hud;
	}
	
	public void tick()
	{
		
	}
	
	public void spawn()
	{
		handler.addObject(new Ball(Game.WIDTH/2 - 12, Game.HEIGHT/2 -12, ID.Ball, handler));
		handler.addObject(new Player(100, Game.HEIGHT/2 - 24, ID.Player, handler));
		handler.addObject(new Player(Game.WIDTH - 140, Game.HEIGHT/2 - 24, ID.Player2, handler));
	}
	
	public void spawnGoals()
	{
		handler.addObject(new Goal(0, Game.HEIGHT /2 - 100, 100, 200, true, this, ID.Goal, handler));
		handler.addObject(new Goal(Game.WIDTH - 107, Game.HEIGHT /2 - 100, 100, 200, false, this, ID.Goal, handler));
	}
	
	public void reset()
	{
		handler.removeAllObjects();
		spawnGoals();
		spawn();
	}
	
}
