#include "Game.h"

Game::Game(TextureManager& textureManager, sf::Vector2u windowSize) : 
    m_window(sf::VideoMode(windowSize), "Arkanoid!"),
    m_textureManager(textureManager),
    m_paddle(sf::Sprite(textureManager.GetTexture("paddle"))),
    m_width(windowSize.x),
    m_height(windowSize.y)
{
    m_window.setFramerateLimit(60);

    InitGame();
}

void Game::Run()
{
    while (m_window.isOpen())
    {
        HandleInput();
        Update();
        Render();
    }
}

void Game::InitGame()
{
    m_paddle.SetPosition({ 300.f, (float)m_height - 10 });

    int n = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            Block block = Block(sf::Sprite(m_textureManager.GetTexture("block")));
            block.SetPosition({ i * 43.f, j * 20.f });
            m_blocks.push_back(block);
        }
    }

    m_balls.push_back(Ball(sf::Sprite(m_textureManager.GetTexture("ball")), { 300.f, 300.f }));
    
    SetTextures();
}

void Game::SetTextures()
{
    for (int i = 0; i < m_blockCount; ++i) 
    {
        m_blocks[i].SetTexture(m_textureManager.GetTextures("block"));
    }
}

void Game::HandleInput()
{
    while (const std::optional event = m_window.pollEvent())
    {
        if (event->is<sf::Event::Closed>()) {
            m_window.close();
        }
    }

    // DISK NEMOZE VYJST Z MAPY CHECK Right
    // AK JE PRAVA SIPKA POSUN VRPAVO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        if (m_paddle.GetPosition().x <= m_width - m_paddle.GetTexture().getSize().x) {
            m_paddle.Move({ 10,0 });
        }
    }

    // DISK NEMOZE VYJST Z MAPY CHECK Left
    // AK JE LAVA SIPKA POSUN VLAVO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        if (m_paddle.GetPosition().x >= 0) {
            m_paddle.Move({ -10,0 });
        }
    }
}

void Game::Update()
{
    std::vector<Ball> newBalls;
    // IDEME ODZADU PRETOZE KVOLI MAZANIU Z VEKTORA CHATGPT
    // V TOMTO CYKLE SA KONTROLUJU KOLIZIE LOPTICIEK
    for (int i = m_balls.size() - 1; i >= 0; --i) {
        Ball& ball = m_balls[i];
        float x = ball.GetPosition().x;
        float y = ball.GetPosition().y;
        float dx = ball.GetDelta().x;
        float dy = ball.GetDelta().y;

        // KONTROLA KOLIZIE LOPTICKY S BLOKOM V PRIPADE KOLIZIE OTOCENIE X SMERU, PRIDANIE LOPTICKY AK CERVENY BLOK
        x += dx;
        for (int i = 0; i < m_blockCount; i++) {
            if (sf::FloatRect({ x + 3, y + 3 }, { 6.f, 6.f }).findIntersection(m_blocks[i].GetSprite().getGlobalBounds()) != std::nullopt)
            {
                Block& block = m_blocks[i];
                if (block.GetType() == BlockType::SPAWN_BALL) {
                    newBalls.push_back(Ball(sf::Sprite(m_textureManager.GetTexture("ball")), block.GetPosition()));
                }
                block.GetSprite().setPosition({ -100, 0 });
                dx = -dx;
            }
        }

        // KONTROLA KOLIZIE LOPTICKY S BLOKOM V PRIPADE KOLIZIE OTOCENIE Y SMERU, PRIDANIE LOPTICKY AK CERVENY BLOK
        y += dy;
        for (int i = 0; i < m_blockCount; i++)
        {
            if (sf::FloatRect({ x + 3, y + 3 }, { 6.f, 6.f }).findIntersection(m_blocks[i].GetSprite().getGlobalBounds()) != std::nullopt)
            {
                Block &block = m_blocks[i];
                if (block.GetType() == BlockType::SPAWN_BALL) {
                    newBalls.push_back(Ball(sf::Sprite(m_textureManager.GetTexture("ball")), block.GetPosition()));
                }
                block.GetSprite().setPosition({ -100, 0 });
                dy = -dy;
            }
        }

        // KONTROLA LOPTICKY CI NARAZILA DO STENY AK ANO OTOC
        if (x < 0 || x > m_width) {
            dx = -dx;
        }

        // GG AK NETRAFI LIETAJUCI TANIER ALE SPODOK - KONIEC HRY AK JE LOPTICIEK VIAC ZMAZE LEN POTICKU
        if (y > m_height) {
            if (m_balls.size() == 1) {
                m_window.close();
            }
                
            m_balls.erase(m_balls.begin() + i);
            continue;
        }

        // KONTROLA LOPTICKY CI NARAZILA DO STROPU AK ANO OTOC
        if (y < 0) {
            dy = -dy;
        }

        // KONTROLA KOLIZIE S HRACOM AK ANO OTOCI SA Y SMER
        if (sf::FloatRect({ x, y }, { 12, 12 }).findIntersection(m_paddle.GetGlobalBounds()) != std::nullopt) {
            dy = -(rand() % 5 + 2);
        }

        ball.SetPosition({ x, y }, { dx, dy });
    }

    // PRIDA LOPTICKY DO HRY
    m_balls.insert(m_balls.end(), newBalls.begin(), newBalls.end());
}

void Game::Render()
{
    m_window.clear();
    m_window.draw(sf::Sprite(m_textureManager.GetTexture("background")));
    for (Ball ball : m_balls) {
        m_window.draw(ball.GetSprite());
    }
    m_window.draw(m_paddle.GetSprite());

    for (int i = 0; i < m_blockCount; i++) {
        m_window.draw(m_blocks[i].GetSprite());
    }

    m_window.display();
}
