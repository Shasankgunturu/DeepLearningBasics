import pandas as pd
import gensim


data = pd.read_csv("/home/shasankgunturu/machineLearning/datasets/clean_tweet_Dec19ToDec20.csv")
data.pop(data.columns[0])
# print(len(data))
# print(data.dtypes)
# print(np.sum(data.isnull().any(axis=1))) # 18 rows which have null value
data.dropna(inplace=True)
# print(len(data))
# print(np.sum(data.isnull().any(axis=1)))
# print(data['sentiment'].unique())
# ax = data.groupby("sentiment").count().plot(kind="bar", title="Positive vs Negative", legend=False)
# ax.set_xticklabels(['Negative', 'Positive'], rotation=0)
# text, sentiment = list(data["text"]), list(data["sentiment"])
reviewed_text = data.text.apply(gensim.utils.simple_preprocess)
model = gensim.models.Word2Vec(window=10, min_count=2, workers=4)
model.build_vocab(reviewed_text, progress_per=1000)
model.train(reviewed_text, total_examples=model.corpus_count, epochs=model.epochs)
model.save("./word2vecForDepressingTweets.model")