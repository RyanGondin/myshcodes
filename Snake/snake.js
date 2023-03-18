// Initialize variables
var canvas;
var ctx;
var tileSize = 10;
var width = 40;
var height = 40;
var score = 0;
var snake = [];
var food = {
    x: Math.floor(Math.random() * width),
    y: Math.floor(Math.random() * height)
};
var direction = "right";

// Initialize the game
function init() {
    canvas = document.getElementById("canvas");
    ctx = canvas.getContext("2d");
    snake[0] = {
        x: Math.floor(width / 2),
        y: Math.floor(height / 2)
    };
    document.addEventListener("keydown", changeDirection);
    setInterval(gameLoop, 100);
}

// Draw the game
function draw() {
    // Clear the canvas
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Draw the snake
    for (var i = 0; i < snake.length; i++) {
        ctx.fillStyle = "#FF0000";
        ctx.fillRect(snake[i].x * tileSize, snake[i].y * tileSize, tileSize, tileSize);
    }

    // Draw the food
    ctx.fillStyle = "#00FF00";
    ctx.fillRect(food.x * tileSize, food.y * tileSize, tileSize, tileSize);

    // Draw the score
    ctx.fillStyle = "#000000";
    ctx.fillText("Score: " + score, 10, 20);
}

// Update the game state
function update() {
    // Move the snake
    var head = {
        x: snake[0].x,
        y: snake[0].y
    };
    switch (direction) {
        case "up":
            head.y--;
            break;
        case "down":
            head.y++;
            break;
        case "left":
            head.x--;
            break;
        case "right":
            head.x++;
            break;
    }
    snake.unshift(head);

    // Check for collisions with the walls
    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
        gameOver();
        return;
    }

    // Check for collisions with the food
    if (head.x == food.x && head.y == food.y) {
        score++;
        food = {
            x: Math.floor(Math.random() * width),
            y: Math.floor(Math.random() * height)
        };
    } else {
        snake.pop();
    }

    // Check for collisions with the snake
    for (var i = 1; i < snake.length; i++) {
        if (head.x == snake[i].x && head.y == snake[i].y) {
            gameOver();
            return;
        }
    }
}

// Game loop
function gameLoop() {
    update();
    draw();
}

// Game over
function gameOver() {
    clearInterval();
    alert("Game Over");
}

// Change direction
function changeDirection(event) {
    switch (event.keyCode) {
        case 37:
            if (direction != "right") direction = "left";
            break;
        case 38:
            if (direction != "down") direction = "up";
            break;
        case 39:
            if (direction != "left") direction = "right";
            break;
        case 40:
            if (direction != "up") direction = "down";
            break;
    }
}

// Initialize the game
init();