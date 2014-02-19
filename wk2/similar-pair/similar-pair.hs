data Tree a = Node a [(Tree a) (Tree a)] |
              EmptyTree
              deriving (Show)
