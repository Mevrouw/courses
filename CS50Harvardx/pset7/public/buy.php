<?php

    // configuration
    require("../includes/config.php"); 
    
    //in case form is submitted:
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {   
        //validate enty
        if (empty($_POST["symbol"]))
        {
            apologize("You must specify a stock to buy");
        }
        if (empty($_POST["shares"]))
        {
            apologize("You must specify a number of shares.");
        }
        if (preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("Invalid number of shares.");
        }


        // find stock user wants to buy
        $stockToBuy = lookup($_POST["symbol"]);
        $symbol = strtoupper($_POST["symbol"]);
       
        //check if symbol is valid
        if ($stockToBuy === false)
        {
            apologize("Symbol not found");    
        }
        
        
        // figure out users total ballance (returns row with id,username, hash, cash)
        $cash = query("SELECT cash from users WHERE id = ?", $_SESSION["id"]);
        
        //calculate total value of stocks to buy
        $value = $stockToBuy["price"]*$_POST["shares"];
            
        // if the user can afford the shares
        if($cash[0]["cash"] < $value)
        {
            apologize("You can't afford this :-P, you own $ {$cash[0]["cash"]} and this costs $ {$value}");
        }
        else
        {    
        // TODO add stock to portfolio 
        $query = query("INSERT INTO portfolio (id, symbol, shares) VALUES (?, ?, ?)
        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], ($symbol), $_POST["shares"]);
                
                
        // TODO update cash
        $query = query("UPDATE users SET cash = cash - ? WHERE id = ?",$value, $_SESSION["id"]);
        
        //add transaction to history
        $query = query("INSERT INTO history (id, symbol, shares, buysell, price) VALUES (?, ?, ?, ?, ?)", 
        $_SESSION["id"], $stockToBuy["symbol"], $_POST["shares"], "BUY", $value );
        
        redirect("/");
        }
        
        
    }
    
    else
    {
        // else -> render form.
        render("buy_form.php", ["title" => "Buy"]);
    }       
?>
