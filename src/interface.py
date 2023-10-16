class Exchange:
    # implement this!

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.balance = initialBalance
        self.trades = []

    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """

        if trade.is_valid():
            if trade.type == "buy":
                if self.balance >= trade.price * trade.quantity:
                    self.balance -= trade.price * trade.quantity
                    self.trades.append(trade)
                    return None
                else:
                    return None
            elif trade.type == "sell":
                self.balance += trade.price * trade.quantity
                self.trades.append(trade)
                return None

    def get_balance(self):
        """Returns the current balance of the exchange."""
        return self.balance

    def get_trades(self):
        """Returns the list of trades that have been added to the exchange."""
        return self.trades
