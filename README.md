# BomberManSJ
**Classic BomberMan game's clone**

This Game was created with Unreal Engine in 5 Days(total of 39 hours). I have used Top Down template in Unreal as a starting point. All the template files are moved to BomberManSJ/Content/TemplateFiles folder. I have added additional code in the template C++ code and they are commented appropriately. All BluePrint codes are done by me.

## Following is the Structure of Classes:
- **`BomberManSJGameManager`** : Responsible for checking Win/Draw conditions, Managing data across rounds/levels. An instance this class' Blueprint is placed in the level.
- **`BomberManSJGameInstance`** : Stores the Data to be carried over upcoming rounds. Keeps its state unchanged during the whole gameplay.
- **`BomberManSJCharacter`** : Represents the player. It is a Template class. Extended to a Blueprint and also Setup with the template. I have added code to sync data with ----`GameInstance` and to place bomb.
- **`BomberManSJPlayerController`** : `Playercontroller` class created with Template. Added code to map keyboard Input to two players and to check win/draw status for inputs.
- **`BomberManSJViewportClient`** : Overridden default `GameViewportClient`. It propagate keyboard events to all players, so that both Players can use Keyboard inputs.
- **`WallBase`** : Represents a Wall object. Determines if a wall is breakable or not. Extended to two Blueprints, `BreakableWall` and `UnBreakableWall`.
- **`Bomb`** : Represents a Bomb object. Responsible for determining the blast locations. Extended to Blueprint to add a timer to go off and call Blast() function.
- **`BombBlastEffect_BP`** : This Blueprint represent the explosion in a single block. If we have an explosion of power 1 and no obstacles are on the way, we will have 5 instances if this Blueprint. If a bomb comes in contact with this instance the explosion will get chained.
- **`PowerUpBase`** : Represents a PowerUp. Only Collission and Visibility is Mmanaged in C++. Other functionalities are added in Blueprint. They are spawned and attched to BreakableWalls. When they blast PowerUp will become visible and collision will be enabled. When a player overlap with the Powerup it will get activated. If it gets in a blast, it will be destroyed.

## Sources used during development:
- [**Static camera Setup**](https://docs.unrealengine.com/en-US/InteractiveExperiences/UsingCameras/Blueprints/index.html)
- [**Displaying FName UE_LOG**](https://answers.unrealengine.com/questions/370716/ue-log-unable-to-print-an-fname-from-uactivemontag.html)
- [**Local Multiplayer using Keyboard**](https://michaeljcole.github.io/wiki.unrealengine.com/Local_Multiplayer_Tips/)

### Note:
Open the [.uproject](BomberManSJ/BomberManSJ/BomberManSJ.uproject) file to bulid the project with Unreal for first time after cloning.
