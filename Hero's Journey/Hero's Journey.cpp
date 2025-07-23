#include <iostream>
#include <ctime>

using namespace std;

void gameStory()
{
    system("clear");

    cout << "______________________" << endl;
    cout << "Welcome to the Hero's Journey!!" << endl;
    cout << "The story begins in Bruch village" << endl;
    cout << "The Villagers were betrayed by their chief" << endl;
    cout << "The Village Cheif wants to sacrifice the villagers to an evil God!!" << endl;
    cout << "The Village Cheif has sent the Mercenary guild to attack the villagers" << endl;
    cout << "Two brothers try to escape their clutches" << endl;
    cout << "______________________" << endl;
}

class Player
{
private:

    int health = 100;
    int maxDamage = 30;
    int minDamage = 20;
    int minHealing = 10;
    int maxHealing = 20;
    int specialMove = 45;



public:

    int specialCounter = 1;

    Player()
    {
        cout << "Player's health is: " << health << endl;
        cout << "______________________" << endl;
        cout << "Player's Attack Range is between " << minDamage << " & " << maxDamage << "." << endl;
        cout << "______________________" << endl;
        cout << "Player's Healing Range is between " << minHealing << " & " << maxHealing << "." << endl;
        cout << "______________________" << endl;
    }

    int GetHealth()
    {
        return health;
    }

    void PlayerHealthAfterTakeDamage()
    {
        if (health <= 0)
        {
            system("clear");

            cout << "======================" << endl;
            cout << "The Mercenaries Won" << endl;
            cout << "The Brothers were not able to escape their terrible fate" << endl;
            cout << "They were Captured and Killed" << endl;
            cout << "Game Over :( " << endl;
            cout << "======================" << endl;
        }
        else
        {
            cout << "Player's health after taking damage is: " << health << endl;
        }
    }

    void TakeDamage(int damage)
    {

        cout << "______________________" << endl;
        cout << "Player recieved " << damage << " damage." << endl;

        health = health - damage;

        PlayerHealthAfterTakeDamage();
    }

    void Heal()
    {

        int randomHeal = (rand() % (maxHealing - minHealing + 1) + minHealing);

        health = health + randomHeal;

        cout << "Player healed " << randomHeal << " Health." << endl;
        cout << "Player's health after healing: " << health << endl;

    }

    int GiveDamage()
    {


        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout << "Player deals " << randomDamage << " damage to the enemy." << endl;

        return randomDamage;
    }

    int SpecialAttack()
    {
        if (specialCounter > 0)
        {
            cout << "______________________" << endl;
            cout << "Special Attack" << endl;
            cout << "Critical Hit!!" << endl;

            if (specialCounter > 0)
            {
                specialCounter--;
            }

            cout << "_____________________" << endl;
            cout << "Special Attack used!!" << endl;
            cout << "Remaing Special Attack: " << specialCounter << endl;
        }

        return specialMove;

    }

    void Defend()
    {
        cout << "______________________" << endl;
        cout << "Player Defends Enemy attack" << endl;
    }

    void RechargeSpecialCounter()
    {
        specialCounter++;

        cout << "_____________________" << endl;
        cout << "Special Counter Recharged." << endl;
        cout << "Number of Special Attack available: " << specialCounter << endl;
        cout << "_____________________" << endl;
    }
};

class Enemy
{

private:

    int health = 100;
    int maxDamage = 30;
    int minDamage = 20;

public:

    Enemy()
    {
        cout << "______________________" << endl;
        cout << "HA HA HA HA, I am the Guild Leader!!" << endl;
        cout << "The Village Chief sent me to Kill you all!!" << endl;
        cout << "You cannot escape your fate." << endl;
        cout << "All of you must DIE!!" << endl;
        cout << "Guild Memeber's ATTACK!!" << endl;

        cout << "______________________" << endl;
        cout << "Mercenary's health is: " << health << endl;
        cout << "Mercenary's Attack range is between " << minDamage << " & " << maxDamage << "." << endl;
    }

    int GetHealth()
    {
        return health;
    }

    void EnemyHealthAfterTakeDamage()
    {
        if (health <= 0)
        {
            system("clear");

            cout << "========================" << endl;
            cout << "The Brothers Have Won" << endl;
            cout << "The Brothers have managed to escape their terrible fate" << endl;
            cout << "The Player has WON!!! :)" << endl;
            cout << "Game Over" << endl;
            cout << "========================" << endl;
        }
        else
        {
            cout << "Enemy's health after taking damage is: " << health << endl;
        }
    }

    void TakeDamage(int damage)
    {


        cout << "______________________" << endl;
        cout << "Enemy recieved " << damage << " damage." << endl;

        health = health - damage;

        EnemyHealthAfterTakeDamage();
    }

    int GiveDamage()
    {


        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout << "______________________" << endl;
        cout << "Enemy deals " << randomDamage << " damage to the player." << endl;

        return randomDamage;
    }

};

void GameLoop(Player player, Enemy Enemy)
{

    char playerChoice;

    do
    {
        cout << "______________________" << endl;
        cout << "Press A to Attack." << endl;
        cout << "Press B to use Special Move." << endl;
        cout << "Press D to Defend." << endl;
        cout << "Press H to Heal." << endl;

        cin >> playerChoice;

        if (playerChoice == 'a' || playerChoice == 'A')
        {
            system("clear");
            //Perform Attack
            Enemy.TakeDamage(player.GiveDamage());

            if (Enemy.GetHealth() > 0)
            {
                cout << "______________________" << endl;
                cout << "Mercenary: It's My turn now!! " << endl;
                player.TakeDamage(Enemy.GiveDamage());
            }
            else
            {
                cout << "Enemy is defeated." << endl;
                player.RechargeSpecialCounter(); // Recharging special counter
                // End battle
            }
        }
        else if (playerChoice == 'h' || playerChoice == 'H')
        {
            system("clear");
            // Perform Heal
            player.Heal();

            if (Enemy.GetHealth() > 0)
            {
                cout << "______________________" << endl;
                cout << "ercenary: It's My turn now!! " << endl;
                player.TakeDamage(Enemy.GiveDamage());
            }
        }
        else if (playerChoice == 'B' || playerChoice == 'b')
        {
            system("clear");
            //Player performs special move

            if (player.specialCounter > 0)
            {
                Enemy.TakeDamage(player.SpecialAttack());

                cout << "______________________" << endl;

                if (Enemy.GetHealth() > 0)
                {
                    cout << "Mercenary: Damn it Hurts!!" << endl;
                    cout << "Mercenary: It's My turn now!! " << endl;
                    cout << "Mercenary: You Will pay for this!!" << endl;
                    player.TakeDamage(Enemy.GiveDamage());
                }
                else
                {
                    cout << "Enemy is defeated." << endl;
                    player.RechargeSpecialCounter(); // Recharging special counter
                    // End battle
                }
            }
            else
            {
                cout << "_____________________" << endl;
                cout << "No Special attacks remaining." << endl;
                cout << "To Recharge Special Attack defeat an enemy." << endl;
                cout << "Try Something else." << endl;
            }

        }
        else if (playerChoice == 'D' || playerChoice == 'd')
        {
            system("clear");
            //Player defends enemy attack
            player.Defend();

            cout << "Mercenary: Tch!! you blocked it." << endl;
        }
        else
        {
            system("clear");
            cout << "______________________" << endl;
            cout << "Invalid Input!! " << endl;
        }

    } while (player.GetHealth() > 0 && Enemy.GetHealth() > 0);

}

int main()
{
    srand(time(0));
    gameStory();
    char userInput;

    do
    {
        cout << "Press S to start or any other key to exit!" << endl;
        cin >> userInput;

        if (userInput == 'S' || userInput == 's')
        {
            Player playerObj;
            Enemy EnemyObj;
            GameLoop(playerObj, EnemyObj);

        }
        else
        {
            cout << "______________________" << endl;
            cout << "Thank you for playing the game." << endl;
        }
    } while (userInput == 'S' || userInput == 's');

}
