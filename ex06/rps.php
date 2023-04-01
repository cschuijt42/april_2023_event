<?php

$player=readline("Choose rock, paper or scissors: ");

$options = ["rock", "paper", "scissors"];

if (!in_array($player, $options)) {
  print("Invalid input!\n");
  exit;
}

$playerno   = array_search($player, $options);
$computerno = array_rand($options);

print("The computer chose $options[$computerno].\n");

if ($playerno == $computerno) {
  print("It's a tie!\n");
}
else if ($playerno - 1 == $computerno || ($playerno == 0 && $computerno == 2)) {
  print("You won!\n");
}
else {
  print("You lost!\n");
}

?>
