import Head from 'next/head'
import Image from 'next/image'
import Header from './01_Header';
import ShowCase from './02_ShowCase';
import CTA from './03_CTA';
import Footer from './04_Footer';

export default function Home() {
  return (
    <div>
      <Head>
        <title>Platypus Programming Language</title>
        <meta name="description" content="Programing Language for Observability Data Pipeline" />
        <link rel="icon" href="/images/icon.png" />
      </Head>

      <main>
        <Header />
        <ShowCase />
        <CTA />
        <Footer />
      </main>
    </div>
  )
}
