
<?php

    // configuration
    require("../includes/config.php"); 
    
    // SQL query
    $rows = query("SELECT symbol,shares FROM portfolio WHERE id=?" , $_SESSION["id"]);

    
    // create a new associative array positions
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => $row["shares"] * $stock["price"]
            ];
        }
    }
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
