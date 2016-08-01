Spring In Action Book Reading
============================

## 06/09/2016 13:21
### plan : page 5 to 25

### Dependency Injection ( DI )
Tie software components together loosely : Objects aren't expected to create or obtain their dependencies ---- dependencies are injected into the objects that need them

* constructor injection 
```java
package com.springinaction.knights;

public class BraveKnight implements Knight {
    private Quest quest;

    public BraveKngiht( Quest quest ) {
        this.quest = quest ;
    }

    public void embarkOnQuest() throws QuestException {
        quest.embark();
    }
}
```

### declarative programming through aspects ( Aspect-Oriented-Programming )

## 06/11/2016 15:04
### plan : page 25 to 35
