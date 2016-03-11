<table class="table table-striped">

    <thead>
        <tr>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Buy/Sell</th>
            <th>price</th>
        </tr>
    </thead>

    <tbody>

    

    <?php foreach ($positions as $position): ?>

        <tr>
            <td><?= $position["datetime"] ?></td>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= $position["buysell"] ?></td>
            <td><?= $position["price"]?></td>
        </tr>

<?php endforeach ?>



    </tbody>

</table>


