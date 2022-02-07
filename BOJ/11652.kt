import kotlin.collections.HashMap

fun main(args: Array<String>) {
    val n = getNumberOfCards()
    val cards: MutableMap<Long, Int> = getCards(n)
    val result = getCardNumber(cards)
    println(result)
}

fun getNumberOfCards() : Int {
    with(System.`in`.bufferedReader()) {
        return readLine().toInt()
    }
}

fun getCards(size: Int) : MutableMap<Long, Int> {
    val cards = HashMap<Long, Int>()

    with(System.`in`.bufferedReader()) {
        repeat(size) {
            val card = readLine().toLong()

            cards[card]?.let {
                cards[card] = it + 1
            }
            if(cards[card] == null) cards[card] = 1
        }
    }

    return cards
}

fun getCardNumber(cards: MutableMap<Long, Int>) : Long {
    var maxCount = 0
    var result = 0L

    cards.forEach { card ->
        if(shouldChange(card, maxCount, result)) {
            maxCount = card.value
            result = card.key
        }
    }
    
    return result
}

fun shouldChange(card: Map.Entry<Long, Int>, maxCount: Int, cardNumber: Long) : Boolean {
    if(card.value > maxCount) return true
    return card.value == maxCount && card.key < cardNumber
}
